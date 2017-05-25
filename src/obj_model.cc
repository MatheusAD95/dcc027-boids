#include "obj_model.h"
#include <cstdio>
#include <cstring>
ObjModel::ObjModel(const char *path) {
  FILE *f = fopen(path, "r");
  if (!f) {
    fprintf(stderr, "%s file not found\n", path);
    exit(1);
  }
  std::vector<glm::vec3> vertices, normals;
  std::vector<glm::vec2> uvs;
  char header[1024];
  while (fscanf(f, "%s", header) != EOF) {
    if (!strcmp(header, "v")) {
      double x, y, z;
      fscanf(f, "%lf %lf %lf", &x, &y, &z);
      vertices.push_back(glm::vec3(x, y, z));
    } else if (!strcmp(header, "vt")) {
      double u, v;
      fscanf(f, "%lf %lf", &u, &v);
      uvs.push_back(glm::vec2(u, -v)); //-v if DDS texture, remove for TGA/BMP
    } else if (!strcmp(header, "vn")) {
      double x, y, z;
      fscanf(f, "%lf %lf %lf", &x, &y, &z);
      normals.push_back(glm::vec3(x, y, z));
    } else if (!strcmp(header, "f")) {
      char v0[128], v1[128], v2[128];
      fscanf(f, "%s %s %s", v0, v1, v2);
      unsigned v[3], uv[3], n[3];
      parseFace(v0, v, uv, n);
      parseFace(v1, v + 1, uv + 1, n + 1);
      parseFace(v2, v + 2, uv + 2, n + 2);
      this->vertices.push_back(vertices[v[0] - 1]);
      this->vertices.push_back(vertices[v[1] - 1]);
      this->vertices.push_back(vertices[v[2] - 1]);
      //this->uvs.push_back(uvs[uv[0] - 1]);
      //this->uvs.push_back(uvs[uv[1] - 1]);
      //this->uvs.push_back(uvs[uv[2] - 1]);
    } else {
      fscanf(f, "%*[^\n]");
    }
  }
  fclose(f);
}
void ObjModel::parseFace(char *s, unsigned *v, unsigned *uv, unsigned *n) {
  int a = 0, b = 0, c = 0;
  while (*s != '/') a = a*10 + *s++ - '0';
  s++; while (*s != '/') b = b*10 + *s++ - '0';
  s++; while (*s != '/') c = c*10 + *s++ - '0';
  *v = a, *uv = b, *n = c;
}
