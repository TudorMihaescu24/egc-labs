#include "clip.h"

namespace egc {

	std::vector<int> computeCSCode(std::vector<vec3> clipWindow, const vec3 p) {
		std::vector<int> code(5, 0);
		if (p.y > clipWindow[2].y) { // Above top boundary
			code[1] = 1;
		}
		if (p.y < clipWindow[0].y) { // Below bottom boundary
			code[2] = 1;
		}
		if (p.x > clipWindow[1].x) { // Right of right boundary
			code[3] = 1;
		}
		if (p.x < clipWindow[0].x) { // Left of left boundary
			code[4] = 1;
		}
		return code;
	}

	bool simpleRejection(std::vector<int> cod1, std::vector<int> cod2) {
		//TO DO - write the code to determine if the two input codes represent 
		//points in the SIMPLE REJECTION case
		if ((cod1[1] == cod2[1] && cod1[1] == 1) ||
			(cod1[2] == cod2[2] && cod1[2] == 1) ||
			(cod1[3] == cod2[3] && cod1[3] == 1) ||
			(cod1[4] == cod2[4] && cod1[4] == 1)) {
			return true;
		}

		return false;
	}

	bool simpleAcceptance(std::vector<int> cod1, std::vector<int> cod2) {
		//TO DO - write the code to determine if the two input codes represent 
		//points in the SIMPLE ACCEPTANCE case
		if (cod1[1] == 0 && cod1[2] == 0 && cod1[3] == 0 && cod1[4] == 0) {
			if (cod2[1] == 0 && cod2[2] == 0 && cod2[3] == 0 && cod2[4] == 0) {
				return true;
			}
		}

		return false;
	}

	//function returns -1 if the line segment cannot be clipped
	int lineClip_CohenSutherland(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
		//TO DO - implement the Cohen-Sutherland line clipping algorithm - consult the laboratory work
		bool finished, rejected, display;
		finished = false;
		std::vector<int> cod1, cod2;
		do {
			cod1 = computeCSCode(clipWindow, p1);
			cod2 = computeCSCode(clipWindow, p2);
			rejected = simpleRejection(cod1, cod2);
			if (rejected == true) {
				finished = true;
			}
			else {
				display = simpleAcceptance(cod1, cod2);
				if (display == true) {
					finished = true;
				}
				else {
					if (cod1[1] == 0 && cod1[1] == cod1[2] && cod1[2] == cod1[3] && cod1[3] == cod1[4]) {
						std::swap(p1, p2);
						std::swap(cod1, cod2);
					}

					if (cod1[1] == 1 && p2.y != p1.y) {
						p1.x = p1.x + (p2.x - p1.x) * (clipWindow[2].y - p1.y) / (p2.y - p1.y);
						p1.y = clipWindow[2].y;
					}
					else if (cod1[2] == 1 && p2.y != p1.y) {
						p1.x = p1.x + (p2.x - p1.x) * (clipWindow[0].y - p1.y) / (p2.y - p1.y);
						p1.y = clipWindow[0].y;
					}
					else if (cod1[3] == 1 && p2.x != p1.x) {
						p1.y = p1.y + (p2.y - p1.y) * (clipWindow[1].x - p1.x) / (p2.x - p1.x);
						p1.x = clipWindow[1].x;
					}
					else if (cod1[4] == 1 && p2.x != p1.x) {
						p1.y = p1.y + (p2.y - p1.y) * (clipWindow[3].x - p1.x) / (p2.x - p1.x);
						p1.x = clipWindow[3].x;
					}
				}
			}
		} while (finished != true);
		return 0;
	}
}

