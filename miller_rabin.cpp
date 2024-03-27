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
// Input: base (b), exponent (e), modulus (m)
// Output: b^e mod m
long power_mod(long long base, long exponent, long modulus)
{
   long result = 1;
   base %= modulus;

   while (exponent > 0)
   {
      // Check odds
      if (exponent & 1)
         result = result * base % modulus;

      base = base * base % modulus;
      exponent >>= 1;
   }

   return result;
}

// ============================
// >>>>>>>>>> Parse n <<<<<<<<<
// >> Parse n to 2^k * m + 1 <<
//
// Input: parsing_number (n), k, m
// Output: 2^k * m + 1
void parse_number(long long parsing_number, int &k, long long &m)
{
   parsing_number = parsing_number - 1;

   // while n even
   while (parsing_number % 2 == 0)
   {
      k++;
      parsing_number = parsing_number / 2;
   }

   m = parsing_number;
}

// ======================
// >>>> Miller Rabin <<<<
// Input: checking_number
// Output: is checking_number prime?
bool miller_rabin(long long checking_number)
{
   // check if n even or = 2
   if (checking_number == 2)
      return true;
   else if (checking_number < 2 || checking_number % 2 == 0)
      return false;

   int k = 0;
   long long m = 0;
   parse_number(checking_number, k, m);

   long long random_number = rand() % (checking_number - 1) + 1;
   long long x = power_mod(random_number, m, checking_number);

   if (x % checking_number == 1)
      return true;

   for (int i = 0; i < k; i++)
   {
      if (x % checking_number == checking_number - 1)
         return true;

      x = power_mod(x, 2, checking_number);
   }

   return false;
}

// ======================
// >>>>>> Benchmark <<<<<
void benchmark()
{
   cout << "Benchmarking... " << flush;

   double total_runtime = 0;
   long long total_test = 0;
   long long total_correct_output = 0;
   long long checking_number = 0;
   long long max_check_number = 1000000000;
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
      bool is_checking_number_prime = miller_rabin(checking_number);
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
