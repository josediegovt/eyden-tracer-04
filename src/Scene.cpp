#include "Scene.h"

#include "ShaderEyelight.h"
#include "ShaderEyelightTextured.h"
#include "ShaderPhong.h"
#include "PrimTriangle.h"
#include "PrimTriangleSmooth.h"
#include "PrimTriangleSmoothTextured.h"

#include <fstream> 


void CScene::ParseOBJ(const std::string& fileName)
{
	std::ifstream file(fileName);

	if (file.is_open()) {
		std::cout << "Parsing OBJFile : " << fileName << std::endl;

		std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 0.5f, 0));
		std::vector<Vec3f> vVertexes;
		
		std::string line;

		int i;

		for (;;) {
			if (!getline(file, line)) break;
			std::stringstream ss(line);
			getline(ss, line, ' ');
			if (line == "v") {
				Vec3f v;
				for (i = 0; i < 3; i++) ss >> v.val[i];
				// std::cout << "Vertex: " << v << std::endl;
				vVertexes.emplace_back(100 * v);
			}
			else if (line == "vt") {
				Vec2f vt;
				Vec2f hvt;
				for (i = 0; i < 2; i++) ss >> vt.val[i];
				hvt = 100 * vt;
				v_textures.emplace_back(hvt);
			}
			else if (line == "vn") {
				Vec3f vn;
				Vec3f hvn;
				for (i = 0; i < 2; i++) ss >> vn.val[i];
				hvn = 100 * vn;
				v_normal.emplace_back(hvn);
			}
			else if (line == "f") {
				Vec3i f;
				for (i = 0; i < 3; i++) ss >> f.val[i];
				// std::cout << "Face: " << f << std::endl;
				Add(std::make_shared<CPrimTriangle>(vVertexes[f.val[0] - 1], vVertexes[f.val[1] - 1], vVertexes[f.val[2] - 1], pShader));
			}
			else {
				std::cout << "Unknown key [" << line << "] met in the OBJ file" << std::endl;
			}
		}

		file.close();
		std::cout << "Finished Parsing" << std::endl;
	} else
		std::cout << "ERROR: Can't open OBJFile" << std::endl;
}
