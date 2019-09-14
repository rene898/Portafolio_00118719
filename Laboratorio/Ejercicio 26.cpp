#include <cstdlib>
#include <iostream>
using namespace std;

// std::complex, std::conj
#include <complex>

// driver program
int main ()
{
  std::complex<double> mycomplex (6,2.0);

  cout << "El conjugado de " << mycomplex << "es: ";

  // use of conj()
  cout << conj(mycomplex) << endl;

	system("pause");
	return 0;
}
