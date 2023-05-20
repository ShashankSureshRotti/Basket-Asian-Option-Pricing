#include "PathDepOption02.h"
#include <cmath>

namespace fre {
    SamplePath Rescale(SamplePath S, double index, double x)
    {
        int m = S.size();
        for(int i = 0; i< m; ++i)
        {
         S[i][index] = S[i][index] * x;   
        }
        return S;
    }
    
    double PathDepOption::PriceByMC(MCModel& Model, long N, double epsilon)
    {
        int d = Model.GetS0().size();
        double H = 0.0;
        SamplePath S(m), Seps(m);
        Vector Heps(d,0.0);
        delta = Heps;


        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H = (i * H + Payoff(S)) / (i + 1.0);
            for (int m = 0; m<d; ++m)
            {
                Seps = Rescale(S, m, 1+ epsilon);
                Heps[m] = (i* Heps[m] + Payoff(Seps)) / (i + 1.0);
            }
        }
        Price = std::exp(-Model.GetR() * T) * H;
        for (int n = 0; n<d; ++n)
        {
            delta[n] = (Heps[n] - H) / (epsilon * Model.GetS0()[n]);
        }
        delta = std::exp(-Model.GetR() * T) * delta;
        return Price;
    }

    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        int d = S[0].size();
        Vector one(d);
        for (int i = 0; i < d; i++) one[i] = 1.0;
        for (int k = 0; k < m; k++)
        {
            Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);
        }
        if (Ave < K) return 0.0;
        return Ave - K;
    }
}
