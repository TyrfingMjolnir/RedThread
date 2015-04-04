#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main( int argc, const char* argv[] ) {
  const unsigned int intBytesWide = sizeof( unsigned int );
  const unsigned int c = 4;

  unsigned int sl, i, j, h, k, l;
  sl = i = j = h = k = l = 0;

  string s;

  for( string line; getline( cin, line ); ) {
    s += line;
  }

  sl = s.length();

  for(  i = 0; i < sl -c ; i++ ) {
      for( j = 0; j < c; j += intBytesWide ) {
        k = i + j;
        for( l = 0; l < intBytesWide; l++ ) {
          h += ( s[ k + l ] ) << ( 24 - l * 8 );
        }
      }
    cout << s[i] << "\t0x" << setfill( '0' ) << setw( 8 ) << hex << h << endl;
  }
  cout << endl << "s[0] = " << s[0] << endl;
}
