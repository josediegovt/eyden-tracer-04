#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorRandom : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		int member;
		for (member = 0; member < n; member++) {
			u[member] = DirectGraphicalModels::random::U<float>();
			v[member] = DirectGraphicalModels::random::U<float>();
			float wm = 1f / n;
			weight[member] = wm;
		}
	}
};


