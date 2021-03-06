#ifndef RS_TRANSFORMER_MINIMIZED_SCALED_H
#define RS_TRANSFORMER_MINIMIZED_SCALED_H

#include "../minimized.h"
#include "../function/scaled.h"
#include <unordered_set>

class Scaled: public TransformerMinimized {
public:
   Scaled(int const scaleSize, TransformerMinimizer &minimizer);
   std::shared_ptr<TransformerFunction const> getFunc() const;
   std::shared_ptr<TransformerFunction const> deserialize(std::string const &serialized) const;
protected:
   void reset();
   void next();
   bool done() const;
   double value(double const r) const;
private:
   long long hash() const;
   std::unordered_set<long long> m_visited;
   int m_bits;
   int m_min1;
   int m_max1;
   int m_min2;
   int m_max2;
   int m_bestMin1;
   int m_bestMax1;
   int m_bestMin2;
   int m_bestMax2;
};

#endif // RS_TRANSFORMER_MINIMIZED_SCALED_H
