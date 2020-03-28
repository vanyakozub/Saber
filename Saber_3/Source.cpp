#include<glm/vec3.hpp>
#include<iostream>

using namespace glm;

vec3* faces_norm(const vec3* verts, const int* faces, int nfaces) 
{
	vec3 tmpvec1;
	vec3 tmpvec2;
	float rationing = 1;
	vec3* face_norm = new vec3[nfaces];
	for (int i = 0; i < nfaces ; i++)
	{
		tmpvec1 = vec3(verts[faces[i * 3]].x - verts[faces[i * 3 + 1]].x, verts[faces[i * 3]].y - verts[faces[i * 3 + 1]].y, verts[faces[i * 3]].z - verts[faces[i * 3 + 1]].z);
		tmpvec2 = vec3(verts[faces[i * 3 + 1]].x - verts[faces[i * 3 + 2]].x, verts[faces[i * 3 + 1]].y - verts[faces[i * 3 + 2]].y, verts[faces[i * 3 + 1]].z - verts[faces[i * 3 + 2]].z);
		face_norm[i].x = tmpvec1.y * tmpvec2.z - tmpvec1.z * tmpvec2.y;
		face_norm[i].y = tmpvec1.z * tmpvec2.x - tmpvec1.x * tmpvec2.z;
		face_norm[i].z = tmpvec1.x * tmpvec2.y - tmpvec1.y * tmpvec2.x;
		rationing = sqrtf(pow(face_norm[i].x, 2) + pow(face_norm[i].y, 2) + pow(face_norm[i].z, 2));
		if (rationing != 0) 
		{
			face_norm[i].x = face_norm[i].x / rationing;
			face_norm[i].y = face_norm[i].y / rationing;
			face_norm[i].z = face_norm[i].z / rationing;
		}
	}
	return face_norm;
}

void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces){
	vec3* surf_norms = faces_norm(verts, faces, nfaces);
	for (int i = 0; i < nverts; i++)
	{
		int rationing = 1;
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
		rationing = sqrtf(pow(normals[i].x, 2) + pow(normals[i].y, 2) + pow(normals[i].z, 2));
		if (rationing != 0)
		{
			normals[i].x /= rationing;
			normals[i].y /= rationing;
			normals[i].z /= rationing;
		}
	}
}
