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
// Input: base (b), exponent (exp), modulus (m)
// Output: b^e mod m
long power_mod(long long b, long exp, long m)
{
   long result = 1;
   b %= m;

   while (exp > 0)
   {
      // Check odds
      if (exp & 1)
         result = result * b % m;

      b = b * b % m;
      exp >>= 1;
   }

   return result;
}

// ============================
// >>>>>>>>>> Parse n <<<<<<<<<
// >> Parse n to 2^k * m + 1 <<
//
// Input: n, k, m
// Output: 2^s * d + 1
void parse_number(long long n, int &s, long long &d)
{
   n = n - 1;

   // while n even
   while (n % 2 == 0)
   {
      s++;
      n = n / 2;
   }

   d = n;
}

// ======================
// >>>> Miller Rabin <<<<
// Input:
//   + checking number (n)
//   + number of round of testing to perform (k)
// Output:
//   + True: probably prime
//   + False: composite
bool miller_rabin(long long n, int k)
{
   // check if n even or = 2
   if (n == 2)
      return true;
   else if (n < 2 || n % 2 == 0)
      return false;

   // repeat k times
   long long y = 0;
   int testing_round = 0;
   while (testing_round < k)
   {
      // Get s and d
      int s = 0;
      long long d = 0;
      parse_number(n, s, d);

      // calc a and x
      long long a = rand() % (n - 1) + 1;
      // cout << "round: " << testing_round << "- a: " << a << endl;
      long long x = power_mod(a, d, n);

      // repeat s times
      for (int i = 0; i < s; i++)
      {
         y = power_mod(x, 2, n);

         // nontrivial square root of 1 modulo n
         if ((y == 1) && (x != 1) && (x != n - 1))
            return false;

         x = y;
      }

      if (y != 1)
         return false;

      testing_round++;
   }

   return true;
}

// ======================
// >>>>>> Benchmark <<<<<
void benchmark()
{
   cout << "Benchmarking... " << flush;

   int number_of_testing_round = 3;
   double total_runtime = 0;
   long long total_test = 0;
   long long total_correct_output = 0;
   long long checking_number = 0;
   // long long max_check_number = 10;
   long long max_check_number = 1000000000;
   // string datasets_file = "./dataset/test.txt";
   string datasets_file = "./dataset/billion-primes.txt";

   // open datasets file
   ifstream file(datasets_file);

   if (!file.is_open())
   {
      cout << "[!] Datasets file does not exist." << endl;
      file.close();
      return;
   }

   string line;
   getline(file, line);
   long long prime = stoll(line);

   // benchmark
   while (checking_number < max_check_number)
   {
      checking_number++;
      total_test++;

      auto start_clock = high_resolution_clock::now();
      bool is_checking_number_prime = miller_rabin(checking_number, number_of_testing_round);
      auto end_clock = high_resolution_clock::now();

      // Calculate miller-rabin runtime (ms)
      duration<double, milli> runtime = end_clock - start_clock;

      // check if miller-rabin return correct output
      if ((is_checking_number_prime && checking_number == prime) || (!is_checking_number_prime && checking_number != prime))
         total_correct_output++;

      // update new prime in file
      if ((checking_number >= prime) && getline(file, line))
         prime = stoll(line);

      total_runtime += runtime.count();

      // cout << " Number: " << checking_number << ", is prime: " << (is_checking_number_prime ? "Yes" : "No") << ", Time: " << runtime.count() << "ms - total_correct:" << total_correct_output << "\n";
   }

   file.close();

   cout << "Done !" << endl
        << endl;

   cout << "=================================" << endl;
   cout << "- Total test        : " << total_test << endl;
   cout << "- Total correct     : " << total_correct_output << endl;
   cout << "- Total runtime     : " << total_runtime << " ms" << endl;
   cout << "=================================" << endl;
   cout << "[>] Average runtime: " << total_runtime / total_test << " ms" << endl;
   cout << "[>] Average correct: " << float(total_correct_output) / total_test * 100 << "%" << endl;
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
   cout << "       \\_______QuanBlue_______/" << endl
        << endl;

   srand(time(NULL));
   benchmark();

   return 0;
}
