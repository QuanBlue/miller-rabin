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

// ============================
// >>>>>>>>>> Parse n <<<<<<<<<
// >> Parse n to 2^k * m + 1 <<
//
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
   cout << "\n\n  Benchmarking..." << endl;

   double total_runtime = 0;
   int total_correct = 0;
   long long n = 0;
   long long max_n = 1000000000;
   string datasets_file = "./dataset/billion-primes.txt";

   // open datasets file
   ifstream file(datasets_file);

   if (!file.is_open())
   {
      cout << "  [!] Datasets file does not exist." << endl;
      file.close();
      return;
   }

   string line;
   getline(file, line);
   long long prime = stoll(line);

   // benchmark
   while (n < max_n)
   {
      n++;

      auto start_clock = high_resolution_clock::now();
      bool is_prime = miller_rabin(n);
      auto end_clock = high_resolution_clock::now();

      // Calculate miller-rabin runtime (ms)
      duration<double, milli> runtime = end_clock - start_clock;

      // check if miller-rabin return correct output
      if ((is_prime && n == prime) || (!is_prime && n != prime))
         total_correct++;

      // update new prime in file
      if ((n >= prime) && getline(file, line))
         prime = stoll(line);

      total_runtime += runtime.count();

      // Print the number and whether it's prime
      // cout << "Prime: " << prime << " - Number: " << n << ", is prime: " << (is_prime ? "Yes" : "No") << ", Time: " << runtime.count() << "ms - total_correct:" << total_correct << "\n";
   }

   file.close();

   cout << "  ========================= " << endl;
   cout << "  _Total test        : " << n << endl;
   cout << "  _Total correct     : " << total_correct << endl;
   cout << "  _Total runtime     : " << total_runtime << " ms" << endl;
   cout << "  ========================= " << endl;
   cout << "  [>] Average runtime: " << total_runtime / n << " ms" << endl;
   cout << "  [>] Average correct: " << float(total_correct) / n * 100 << "%" << endl;
}

// ======================
// >>>>>>> Main <<<<<<
int main()
{
   cout << "  /=================================\\" << endl;
   cout << "  |                                 |" << endl;
   cout << "  |          MILLER RABIN           |" << endl;
   cout << "  |      ____________________       |" << endl;
   cout << "  |  Probabilistic primality test   |" << endl;
   cout << "  |                                 |" << endl;
   cout << "  \\=================================/" << endl;
   cout << "       \\_______QuanBlue_______/" << endl;

   srand(time(NULL));
   benchmark();

   return 0;
}
