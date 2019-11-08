#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorStratified : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
				// --- PUT YOUR CODE HERE ---
		int c = 0;
		int w = 0;
		int n_sqrt = sqrt(n);
		float wv;
		float e1;
		float e2;
		while (w < n_sqrt) {
			for (int i = 0; i < n_sqrt; i++) {
				e1 = DirectGraphicalModels::random::U<float>();
				e2 = DirectGraphicalModels::random::U<float>();
				u[c] = (w + e1) / n_sqrt;
				v[c] = (i + e2) / n_sqrt;
				wv = 1f / n;
				weight[c] = wv;
				c++;
			}
			w++;
		}
	}
};
