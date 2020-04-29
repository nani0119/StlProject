#ifndef UTIL_CHRONO_DURATION_H
#define UTIL_CHRONO_DURATION_H

#include <ratio>
#include <chrono>
#include <iostream>

template <typename V, typename R>
std::ostream& operator<<(std::ostream&os, const std::chrono::duration<V,R>& d)
{
   os << "[ " << d.count() << " of " << R::num << "/" <<R::den << " ]";
   return os;	
}

#endif /* ifndef UTIL_CHRONO_DURATION_H*/
