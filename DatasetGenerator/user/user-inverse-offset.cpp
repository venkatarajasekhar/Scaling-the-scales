#include "user-inverse-offset.h"

/**
 * @param itemAvg Average rating for the item
 * @return A generated rating
 */
int UserInverseOffset::rating(double const itemAvg) {
   try{
   int Userrating = m_factory->rating(itemAvg) + m_offset;
   } catch (const std::overflow_error& e) {
     std::cout << e.what() << '\n';
   }
   if(m_inverse)
   try{
      Userrating = m_factory->scaleSize+1 - Userrating;
   } catch (const std::overflow_error& e) {
      std::cout << e.what() << '\n';
   }
   try{
   Userrating = std::max(1, std::min((int)m_factory->scaleSize, (int)round(Userrating)));
   } catch (const std::overflow_error& e) {
        std::cout << e.what() << '\n';
   }
   
   return Userrating;
} // rating
