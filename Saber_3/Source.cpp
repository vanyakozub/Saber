#include<glm/vec3.hpp>
#include<iostream>

using namespace glm;

vec3* faces_norm(const vec3* verts, const int* faces, int nfaces) 
{
	vec3 tmpvec1;
	vec3 tmpvec2;
	float normirovka = 1;
	vec3* face_norm = new vec3[nfaces];
	for (int i = 0; i < nfaces ; i++)
	{
		tmpvec1 = vec3(verts[faces[i * 3]].x - verts[faces[i * 3 + 1]].x, verts[faces[i * 3]].y - verts[faces[i * 3 + 1]].y, verts[faces[i * 3]].z - verts[faces[i * 3 + 1]].z);
		tmpvec2 = vec3(verts[faces[i * 3 + 1]].x - verts[faces[i * 3 + 2]].x, verts[faces[i * 3 + 1]].y - verts[faces[i * 3 + 2]].y, verts[faces[i * 3 + 1]].z - verts[faces[i * 3 + 2]].z);
		//normirovka = sqrtf(pow(tmpvec1.y * tmpvec2.z - tmpvec1.z * tmpvec2.y, 2) + pow(tmpvec1.z * tmpvec2.x - tmpvec1.x * tmpvec2.z, 2) + pow(tmpvec1.x * tmpvec2.y - tmpvec1.y * tmpvec2.x, 2));
		
		face_norm[i].x = tmpvec1.y * tmpvec2.z - tmpvec1.z * tmpvec2.y;
		face_norm[i].y = tmpvec1.z * tmpvec2.x - tmpvec1.x * tmpvec2.z;
		face_norm[i].z = tmpvec1.x * tmpvec2.y - tmpvec1.y * tmpvec2.x;
		std::cout << face_norm[i].x << "\t";
		std::cout << face_norm[i].y << "\t";
		std::cout << face_norm[i].z << "\t";
		std::cout << std::endl;
		normirovka = sqrtf(pow(face_norm[i].x, 2) + pow(face_norm[i].y, 2) + pow(face_norm[i].z, 2));
		std::cout << "Normirovka" << normirovka << "\t";
		std::cout << std::endl;
		if (normirovka != 0) 
		{


			face_norm[i].x = face_norm[i].x / normirovka;
			face_norm[i].y = face_norm[i].y / normirovka;
			face_norm[i].z = face_norm[i].z / normirovka;
		}
	}
	return face_norm;
}

void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces){
	vec3* surf_norms = faces_norm(verts, faces, nfaces);
	for (int i = 0; i < nfaces; i++)
	{
		std::cout << surf_norms[i].x << "\t";
		std::cout << surf_norms[i].y << "\t";
		std::cout << surf_norms[i].z << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < nverts; i++)
	{
		int normirovka = 1;
		int cnt;
		cnt = 0;
		for (int j = 0; j < nfaces; j++)
		{
			
			if (faces[j * 3] == i || faces[j * 3 + 1] == i || faces[j * 3 + 2] == i)
			{
				normals[i].x += surf_norms[j].x;
				normals[i].y += surf_norms[j].y;
				normals[i].z += surf_norms[j].z; 
				cnt++;
			}
		}
		
		if (cnt != 0)
		{
			normals[i].x /= cnt;
			normals[i].y /= cnt;
			normals[i].z /= cnt;
		}
		else
		{
			std::cout << "not in aproximation" << std::endl;
		}
		normirovka = sqrtf(pow(normals[i].x, 2) + pow(normals[i].y, 2) + pow(normals[i].z, 2));
		if (normirovka != 0)
		{
			normals[i].x /= normirovka;
			normals[i].y /= normirovka;
			normals[i].z /= normirovka;
		}
	}
}



int main()
{
	vec3 v1;
	v1 = vec3(3.0, 6.0, 5.0);
	int nverts = 10;

	int nfaces = 16;
	vec3* verts = new vec3[nverts];
	verts[0] = vec3(0, 0, 0);
	verts[1] = vec3(1, 0, 0);
	verts[2] = vec3(1, 1, 0);
	verts[3] = vec3(0, 1, 0);
	verts[4] = vec3(0, 0, 1);
	verts[5] = vec3(1, 0, 1);
	verts[6] = vec3(1, 1, 1);
	verts[7] = vec3(0, 1, 1);
	verts[8] = vec3(0.5, 0.5, 0);
	verts[9] = vec3(0.5, 0.5, 1);
	/*for (int i = 0; i < nverts; i++)
	{
		verts[i] = vec3((i + 3) % 5, (i - 2) % 5, i % 5);
	}*/
	int* faces = new int[nfaces * 3];
	/*for (int i = 0; i < nfaces * 3; i++)
	{
		faces[i] = (i + abs(rand()) ) % nverts;
	}*/

	faces[0] = 0;
	faces[1] = 4;
	faces[2] = 5;
	faces[3] = 0;
	faces[4] = 5;
	faces[5] = 1;
	faces[6] = 1;
	faces[7] = 5;
	faces[8] = 6;
	faces[9] = 1;
	faces[10] = 6;
	faces[11] = 2;
	faces[12] = 2;
	faces[13] = 6;
	faces[14] = 7;
	faces[15] = 2;
	faces[16] = 7;
	faces[17] = 3;
	faces[18] = 3;
	faces[19] = 7;
	faces[20] = 4;
	faces[21] = 3;
	faces[22] = 4;
	faces[23] = 0;
	faces[24] = 8;
	faces[25] = 5;
	faces[26] = 4;
	faces[27] = 8;
	faces[28] = 6;
	faces[29] = 5;
	faces[30] = 8;
	faces[31] = 7;
	faces[32] = 6;
	faces[33] = 8;
	faces[34] = 4;
	faces[35] = 7;
	faces[36] = 9;
	faces[37] = 5;
	faces[38] = 4;
	faces[39] = 9;
	faces[40] = 6;
	faces[41] = 5;
	faces[42] = 9;
	faces[43] = 7;
	faces[44] = 6;
	faces[45] = 9;
	faces[46] = 4;
	faces[47] = 7;
	
	//vec3* surf_norms = faces_norm(verts,faces, nfaces);

	
		/*for (int i = 0; i < nfaces; i++) 
		{
			std::cout << surf_norms[i].x << "\t";
			std::cout << surf_norms[i].y << "\t";
			std::cout << surf_norms[i].z << "\t";
			std::cout << std::endl;
		}
		std::cout << std::endl;*/
	

	/*for (int i = 0; i < nverts; i++) {
		std::cout << verts[i].x << "\t";
		std::cout << verts[i].y << "\t";
		std::cout << verts[i].z << "\t";
		std::cout << std::endl;
	}*/
	std::cout << std::endl;
	vec3* normals = new vec3[nverts];
	for (int i = 0; i < nverts; i++)
	{
		normals[i].x = 0;
		normals[i].y = 0;
		normals[i].z = 0;
	}
	calc_mesh_normals(normals, verts, faces, nverts, nfaces);
	for (int i = 0; i < nverts; i++)
	{
		std::cout << normals[i].x << "\t";
		std::cout << normals[i].y << "\t";
		std::cout << normals[i].z << "\t";
		std::cout << std::endl;
	}
}