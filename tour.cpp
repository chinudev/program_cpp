

// Initialize using {}

int i1 {7.8}; // not very useful 
auto b {true}; // types can be auto-deduced 
vector<int> vec = {1,2,3}; // useful

// const

constexpr double sq(double x) { return x*x;} // like macro
constexpr double max1 = 1.4*sq(17);          // have to use constexpr function

// Enum class 

enum class Color {red, blue, green};
Color x = red; 
Color z = Color::red;

variant<Node*, int> v;
if (holds_alternative<int>(v)) {
    count << get<int>(v); 
}

// Modularity

namespace my_name {
  using namespace std;
  class complex {...}
}

try {
    throw std::out_of_range("testing");
} catch(out_of_range& err) { //catch by reference
    cout << "who threw that" << endl;
}

// assert
static_assert( 4 <= sizeof(int), "integer too small"); 

// classes

class base_interface 
{
    virtual run() = 0; // pure virtual function makes class abstract
    virtua ~base_interface();
};






