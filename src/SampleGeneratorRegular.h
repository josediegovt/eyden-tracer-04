#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorRegular : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE ---
		int c = 0;
		int w = 0;
		int i = 0;
		int n_sqrt = sqrt(n);
		float wv;
		while( w < n_sqrt ){
			for(i = 0; i < n_sqrt; i++){
				u[c] = (w + 0.5f) / n_sqrt;
				v[c] = (i + 0.5f) / n_sqrt;
				wv = 1f / n;
				weight[c] = wv;
				c++;
			}
			w++;
		}
	}
};
