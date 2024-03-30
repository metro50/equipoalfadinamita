/**
* Simple abstraction of an N-dimentional matrix,
* based on std::vector and offering an STL-like interface.
* 
* You can use/modify/redistribute this code at your own risk for any purpouse.
* 
* @version 2016-05-23-a
* @author Pablo Novara
**/

#include <vector>
#include <stdexcept>
#include <algorithm>

/**
* N-dimentional homogeneous and dynamic matrix.
*
* matrix is a templatized type; the two template arguments are the element type
* T and the dimentionality D of the matrix (will be 2 if it's omitted)
**/
template<typename T, int D=2> class matrix;

/**
* Partial specialization for 1D. It is just a wrapper for std::vector
*
* For individual methods descriptions either see the general case matrix 
* implementation, or assume they work just like std::vector's ones.
**/
template<typename T>
class matrix<T,1> : private std::vector<T> {
	using base_t = std::vector<T>;
public:
	matrix() = default;
	matrix(const matrix&) = default;
	matrix(matrix&&) = default;
	matrix(int n, const T &x=T()) :base_t(n,x) {}
	template<typename U>
	matrix(const std::initializer_list<U> &l) : base_t(l) {}
	matrix &operator=(const matrix&) = default;
	matrix &operator=(matrix&&) = default;
	template<typename U>
	matrix &operator=(const std::initializer_list<U> &l) { base_t::operator=(l); return *this; }
	void resize(int n, T x=T()) {
		base_t::resize(n,x);
	}
	std::size_t size(int dim) const {
		if(dim!=0) throw std::invalid_argument("argumento incorrecto en llamada a matrix::size(int)");
		return base_t::size();
	}
	using base_t::clear;
	using base_t::begin;
	using base_t::end;
	using base_t::at;
	using base_t::operator[];
};


/**
* General case implementation, an ND matrix if an std::vector of (N-1)D matrixes
**/
template<typename T, int D>
class matrix : private std::vector<matrix<T,D-1>> {
	using row_t = matrix<T,D-1>;
	using base_t = std::vector<row_t>;
public:
	/// default constructor, makes an empty (0x0) matrix
	matrix() = default;
	/// default copy constructor
	matrix(const matrix&) = default;
	/// default move constructor
	matrix(matrix&&) = default;
	/// constructor for size (D integers) and optional initial value (default is T())
	template<typename ... Ints >
	matrix(int n, Ints... ns) : base_t(n,row_t(ns...)) {}
	
	/// default operator = for rvalues (copy)
	matrix &operator=(const matrix<T,D>&) = default;
	/// default operator = for lvalues (move)
	matrix &operator=(matrix&&) = default;
	
	/// constructor for an initializer list (matrix m = {{1,2},{3,4}};), only for D==2
	template<typename U>
	matrix(const std::initializer_list<std::initializer_list<U>> &l) {
		std::size_t max_w = 0;
		for (const auto &x:l) {
			base_t::push_back(x);
			max_w = std::max(max_w,x.size());
		}
		resize(size(0),max_w,T());
	}
	
	/// operator = for an initializer list (m={{1,2},{3,4}};), only for D==2
	template<typename U>
	matrix &operator=(const std::initializer_list<std::initializer_list<U>> &l) {
		return (*this)=matrix(l);
	}
	
	/// resizes the matrix preserving values, receives all the new dimensions (D
	/// integers) and optionally a value (default is T()) for filling the new positions 
	template<typename ... Ints>
	void resize(int n, Ints ... ns) {
		for(auto &row:*this) row.resize(ns...);
		base_t::resize(n,row_t(ns...));
	}
	
	/// returns the size of the matrix in dimention dim (dim should be in [0...D-1])
	std::size_t size(int dim) const {
		if (dim==0 || base_t::empty()) return base_t::size();
		else return base_t::operator[](0).size(dim-1);
	}
	
	/// clears all the matrix's content, will leave it as default constructed (0x0) matrix
	using base_t::clear;
	
	/// begin and end are present just for enabling the use of for-range loops
	using base_t::begin;
	/// begin and end are present just for enabling the use of for-range loops
	using base_t::end;
	
	/// for accessing one matrix "row", inherited from std::vector (both const
	/// and no-const versions, does not checks indexes)
	using base_t::operator[];
	
	/// similar to operator[] (this one does check indexes)
	using base_t::at;
};

/// helper function for using sort on std::vectors withouth knowing about iterators
/// (not directly related to matrix)
template<typename T>
void sort(std::vector<T> &v) {
	std::sort(v.begin(),v.end());
}
