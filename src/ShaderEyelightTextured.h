#pragma once

#include "ShaderEyelight.h"
#include "texture.h"

/**
* @brief Eye-light shader with support of textures class
*/
class CShaderEyelightTextured : public CShaderEyelight
{
public:
	/**
	 * @brief Constructor
	 * @details This is a light-source-free shader
	 * @param color The color of the object
	 * @param fileName The path to the file with texture
	 */
	CShaderEyelightTextured(Vec3f color = RGB(0.5f, 0.5f, 0.5f), const std::string& fileName = {})
		: CShaderEyelight(color)
		, texture(fileName)
	{}
	virtual ~CShaderEyelightTextured(void) = default;
  
	virtual Vec3f Shade(const Ray& ray) const override
	{
		// --- PUT YOUR CODE HERE ---
		Vec2f uv_vec;
		Vec3f tx;
		Vec3f eyelight_color;
		uv_vec = ray.hit->getUV(ray);
		tx = texture.GetTexel(uv_vec[0], uv_vec[1]);
		eyelight_color = CShaderEyelight::Shade(ray);
		Vec3f res = tx.mul(eyelight_color);
		return res;
	}

private:
	Texture texture;
};
