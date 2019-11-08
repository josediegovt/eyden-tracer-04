#pragma once

#include "PrimTriangle.h"
#include "IShader.h"

/**
* @brief Smooth triangle primitive class interface
*/
class CPrimTriangleSmooth : public CPrimTriangle
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 * @param na Normal at the first vertex
	 * @param nb Normal at the second vertex
	 * @param nc Normal at the third vertex
	 * @param pShader Pointer to the shader to be applied for the prim
	 */
	CPrimTriangleSmooth(Vec3f a, Vec3f b, Vec3f c, Vec3f na, Vec3f nb, Vec3f nc, std::shared_ptr<IShader> pShader)
		: CPrimTriangle(a, b, c, pShader)
		, m_na(na)
		, m_nb(nb)
		, m_nc(nc)
	{}
	virtual ~CPrimTriangleSmooth(void) = default;

	virtual Vec3f getNormal(const Ray& ray) const override
	{
		// assume u/v coordinates in ray correspond to beta(u) and gamma(v) barycentric coordinates of 
		// hitpoint on triangle (have to be stored like this in the intersection code!)
		// --- PUT YOUR CODE HERE ---
		Vec3f n;
		float x = (1 - ray.u - ray.v);
		Vec3f s = ((m_nc * ray.u) + (m_nb * ray.v));
		n = m_na * x + s;
		Vec3f nor = normalize(n);
		return nor;
	}

private:
	Vec3f m_na;	///< vertex a normal
	Vec3f m_nb;	///< vertex b normal
	Vec3f m_nc; ///< vertex c normal
};
