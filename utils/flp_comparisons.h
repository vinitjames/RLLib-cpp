#ifndef FLP_COMPARISONS_H
#define FLP_COMPARISONS_H


#include<limits>
#include <cmath>

template <typename T>
inline bool approximately_equal(const T& val1, const T& val2,
						 const T& epsilon = std::numeric_limits<T>::epsilon()){
	return std::abs(val1 - val2) <= ((std::abs(val1) < std::abs(val2)
									  ? std::abs(val2) : std::abs(val1)) * epsilon);
}


template <typename T>
inline bool essentially_equal(const T& val1, const T& val2, const T& epsilon = std::numeric_limits<T>::epsilon()){
	return std::abs(val1 - val2) <= ((std::abs(val1) > std::abs(val2)
									  ? std::abs(val2) : std::abs(val1)) * epsilon);
}

template <typename T>
inline bool greater_than(const T& val1, const T& val2,
						 const T& epsilon = std::numeric_limits<T>::epsilon()){
	return std::abs(val1 - val2) > ((std::abs(val1) < std::abs(val2)
									  ? std::abs(val2) : std::abs(val1)) * epsilon);
}

template <typename T>
inline bool less_than(const T& val1, const T& val2,
					  const T& epsilon = std::numeric_limits<T>::epsilon()){
	return std::abs(val2 - val1) > ((std::abs(val1) < std::abs(val2)
									  ? std::abs(val2) : std::abs(val1)) * epsilon);
}
		
#endif /* FLP_COMPARISONS_H */
