// --------------------------------------
// - Miler rabin
// - This code is in Long long (64bits)
// dataset:
// list of small prime: https://t5k.org/lists/small/
// generate prime: https://bigprimes.org/
// test is prime online: https://www.dcode.fr/primality-test
// --------------------------------------

#include <iostream>
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// ======================
// >>>>>> Power Mod <<<<<
// Input: b (base), e (exponent), m (modulus)
// Output: b^e mod m
long power_mod(long long b, long e, long m)
{
   long result = 1;
   b %= m;

   while (e > 0)
   {
      // Check odds
      if (e & 1)
      {
         result = result * b % m;
      }

      // b overflew before calc modular, so use long long for base.
      b = b * b % m;
      e >>= 1;
   }

   return result;
}

// ======================
// >>>>>>> Parse n <<<<<<
// Input: n, k, m
// Output: 2^k * m + 1
void parse_n(long long n, int &k, long long &m)
{
   n = n - 1;

   // while n even
   while (n % 2 == 0)
   {
      k++;
      n = n / 2;
   }

   m = n;
}

// ======================
// >>>> Miller Rabin <<<<
// Input: n
// Output: is n prime?
bool miller_rabin(long long n)
{

   // check if n even or = 2
   if (n == 2)
      return true;
   else if (n < 2 || n % 2 == 0)
      return false;

   int k = 0;
   long long m = 0;
   parse_n(n, k, m);

   // pick random a (1, n-1)
   long long a = rand() % (n - 1) + 1;
   long long b = power_mod(a, m, n);

   if (b % n == 1)
      return true;

   for (int i = 0; i < k; i++)
   {
      if (b % n == n - 1)
         return true;
      b = power_mod(b, 2, n);
   }

   return false;
}

// ======================
// >>>>>> Benchmark <<<<<
void benchmark()
{

   double total_runtime = 0;
   int total_correct = 0;
   int total_test = 0;

   // open datasets file
   ifstream file("./dataset/100_18digits_primes.txt");

   // test each line in datasets
   string line;
   while (getline(file, line))
   {
      total_test++;
      long long n = stoll(line);

      auto start = high_resolution_clock::now();
      bool is_prime = miller_rabin(n);
      auto end = high_resolution_clock::now();

      // Calculate duration
      duration<double, milli> ms_double = end - start;

      if (is_prime)
      {
         total_correct++;
      }

      total_runtime += ms_double.count();

      // Print the number and whether it's prime
      cout << "Number: " << n << ", is prime: " << (is_prime ? "Yes" : "No")
           << ", Time: " << ms_double.count() << "ms\n";
   }

   file.close();

   cout << " ================== " << endl;
   cout << "Total test: " << total_test << endl;
   cout << "Total correct: " << total_correct << endl;
   cout << "Average runtime: " << total_runtime / total_test << " ms\n";
   cout << "Average correct: " << float(total_correct) / total_test * 100 << "%\n";
}

// ======================
// >>>>>>> Main <<<<<<
int main()
{
   // srand(time(NULL));

   // long long n;

   // cout << "=================================================" << endl;
   // cout << "==                 Miller Rabin                ==" << endl;
   // cout << "==         ---------------------------         ==" << endl;
   // cout << "=================================================" << endl;

   // cout << "\n> Input n:";

   // // Flush input to prevent infinity loop
   // cin >> n;
   // cin.clear();
   // fflush(stdin);

   // if (miller_rabin(n))
   //    cout << n << " is prime";
   // else
   //    cout << n << " is not prime";

   // cout << endl;
   benchmark();

   return 0;
}
