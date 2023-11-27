/*
 * Ref: https://www.reddit.com/r/numbertheory/comments/183sxje/multiplicative_reversibility_no_primitive_roots/
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// Vectorizes numbers in base. This is to compensate for numbers which are multiplicatively reversible but with
// bases that are too large to represent in ASCII set.
vector<int> numInBase(int x, int base, vector<int> vec)
{
   if ( x < base )
   {
      vec.push_back(x);
      return vec;
   }

   int rem = x%base;
   vec.push_back(rem);
   return numInBase(x/base, base, vec);
}

// Reverse the vector
vector<int> reverseVec(vector<int> v) {
	reverse(v.begin(), v.end());
	return v;
}

// Functionallity not used, but can be used to print out the number in vectorized base notation
// i.e., 16 in base 5 is 1*5^0, 3*5^1 which will give the string "1,3,"
string vec_string(vector<int> v){
	string s = "";
	for(int i : v){
		s += to_string(i);
		s.push_back(',');
	}
	return s;
}

int main(){


	for(int n = 8; n <= 1000; n++){
		cout << "------------ number = " << n << " ------------------" << endl;

		for(int b = 2; b < n; b++){
			for(int k = 2; k <= n; k++){
				vector<int> vec_rep = numInBase(n, b, {});
				vector<int> vec_mult = numInBase(n*k, b, {});
				vector<int> vec_rev = reverseVec(vec_rep);

				if(vec_mult == vec_rev){
					cout << "\t| b: " << b << " | k: " << k << " | n: " << n  << endl;
				}

			}
		}
	}

}
