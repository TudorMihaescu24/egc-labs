	#include "clip.h"


	namespace egc {

		int lineClip_CyrusBeck(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
       
            if (p1 == p2)
            {
                return -1;
            }

            float tE = 0;
            float tL = 1.0;

            int n = clipWindow.size();

            std::vector<vec3> NiList;
            for (size_t i = 0; i < n; i++) {
                vec3 pE = clipWindow[i];
                vec3 pL = clipWindow[(i + 1) % n];
                vec3 vector = pL - pE;
                vec3 normal = vector.normalize();
                NiList.push_back(normal);
            }

          
            for (size_t i = 0; i < n; i++) {
                vec3 pE = clipWindow[i];
                vec3 pL = clipWindow[(i + 1) % n];
                vec3 vector = pL - pE;
                vec3 normal = NiList[i]; 

                float NiDotD = dotProduct(normal, p2 - p1);

                if (NiDotD != 0) {
                    float t = dotProduct(normal, pE - p1) / NiDotD;

                    if (NiDotD > 0) {
                        tE = std::max(tE, t);
                    }
                    else {
                        tL = std::min(tL, t);
                    }
                }
            }

          
            if (tE > tL) {
                return -1; 
            }
            else {
      
                vec3 newP1, newP2;
                newP1.x = p1.x + (p2.x - p1.x) * tE;
                newP1.y = p1.y + (p2.y - p1.y) * tE;
                newP1.z = p1.z + (p2.z - p1.z) * tE;


                newP2.x = p1.x + (p2.x - p1.x) * tL;
                newP2.y = p1.y + (p2.y - p1.y) * tL;
                newP2.z = p1.z + (p2.z - p1.z) * tL;
              
                p1 = newP1;
                p2 = newP2;

                return 0; 
            }
		}

	
	}

