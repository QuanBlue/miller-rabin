<h1 align="center">
  <img src="assets/miller-rabin-logo.png" alt="icon" width="200"></img>
  <br>
  <b>Miller Rabin</b>
</h1>

<p align="center">Probabilistic Primality test.</p>

<!-- Badges -->
<p align="center">
  <a href="https://github.com/QuanBlue/miller-rabin/graphs/contributors">
    <img src="https://img.shields.io/github/contributors/QuanBlue/miller-rabin" alt="contributors" />
  </a>
  <a href="">
    <img src="https://img.shields.io/github/last-commit/QuanBlue/miller-rabin" alt="last update" />
  </a>
  <a href="https://github.com/QuanBlue/miller-rabin/network/members">
    <img src="https://img.shields.io/github/forks/QuanBlue/miller-rabin" alt="forks" />
  </a>
  <a href="https://github.com/QuanBlue/miller-rabin/stargazers">
    <img src="https://img.shields.io/github/stars/QuanBlue/miller-rabin" alt="stars" />
  </a>
  <a href="https://github.com/QuanBlue/miller-rabin/issues/">
    <img src="https://img.shields.io/github/issues/QuanBlue/miller-rabin" alt="open issues" />
  </a>
  <a href="https://github.com/QuanBlue/miller-rabin/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/QuanBlue/miller-rabin.svg" alt="license" />
  </a>
</p>

<p align="center">
  <b>
    <a href="https://github.com/QuanBlue/miller-rabin">Documentation</a> •
    <a href="https://github.com/QuanBlue/miller-rabin/issues/">Report Bug</a> •
    <a href="https://github.com/QuanBlue/miller-rabin/issues/">Request Feature</a>
  </b>
</p>

<br />

<details open>
<summary>Table of Contents</summary>

-  [Getting Started](#getting-started)
   -  [Prerequisites](#prerequisites)
   -  [Run Locally](#run-locally)
-  [Benchmark](#benchmark)
-  [Roadmap](#roadmap)
-  [Contributors](#contributors)
-  [Credits](#credits)
-  [License](#license)

# Getting Started

## Prerequisites

Before proceeding with the installation and usage of this project, ensure that you have the following prerequisites in place:

-  **g++**: the GNU C++ complier, install [here for VSCode](https://code.visualstudio.com/docs/cpp/config-mingw)

## Run Locally

**Step 1:** Extract dataset file at `./dataset/billion-primes.7z`

> You can download at [here](https://github.com/bauripalash/bpp?fbclid=IwAR0z5uRxI1fYtzv9THQb5gK9iGbNGbEhZXM6av7V26RSVVOwcLU79AcAYlA_aem_AR9i2LabMtvQqOqQlC2kkDWeMgFsbRFR5XC9axt7Q_q6G3IbwCCDX9wqDMobiJ_M_UZFfk3cQsL3JQX2wo7btHh-)

**Step 2:** Compile program, it will generate `miller_rabin` file (executable file) from `miller_rabin.cpp`:

```bash
g++ -o miller_rabin miller_rabin.cpp
```

**Step 3:** Run executable file and wait :))

```bash
./miller_rabin
```

# Benchmark

Using a simple C++ script with `3 testing rounds` and `20 benchmark rounds`, which took about total `02:10:09 (7808.97 sec)`

> **OS:** Ubuntu 22.04.4 LTS x86_64  
> **CPU:** Intel i7-9750H (12) @ 4.500GHz

```
      /=================================\
      |                                 |
      |          MILLER RABIN           |
      |      ____________________       |
      |  Probabilistic primality test   |
      |                                 |
      \=================================/
           \_______QuanBlue_______/

================[ BENCHMARK ]=================
                     ***
[+] Benchmarking round <1>...Done! - Run in 388319.787326 (ms)
[+] Benchmarking round <2>...Done! - Run in 384664.877112 (ms)
[+] Benchmarking round <3>...Done! - Run in 382277.636380 (ms)
[+] Benchmarking round <4>...Done! - Run in 379976.218502 (ms)
[+] Benchmarking round <5>...Done! - Run in 380489.474973 (ms)
[+] Benchmarking round <6>...Done! - Run in 389533.944643 (ms)
[+] Benchmarking round <7>...Done! - Run in 391716.273947 (ms)
[+] Benchmarking round <8>...Done! - Run in 394091.112519 (ms)
[+] Benchmarking round <9>...Done! - Run in 397559.886904 (ms)
[+] Benchmarking round <10>...Done! - Run in 398380.716659 (ms)
[+] Benchmarking round <11>...Done! - Run in 394647.207036 (ms)
[+] Benchmarking round <12>...Done! - Run in 396271.656236 (ms)
[+] Benchmarking round <13>...Done! - Run in 400568.897206 (ms)
[+] Benchmarking round <14>...Done! - Run in 390854.019236 (ms)
[+] Benchmarking round <15>...Done! - Run in 389165.656980 (ms)
[+] Benchmarking round <16>...Done! - Run in 391387.991854 (ms)
[+] Benchmarking round <17>...Done! - Run in 390859.553101 (ms)
[+] Benchmarking round <18>...Done! - Run in 382307.175902 (ms)
[+] Benchmarking round <19>...Done! - Run in 395381.857096 (ms)
[+] Benchmarking round <20>...Done! - Run in 390516.020479 (ms)
----------------------------------------------
Total runtime for 20 benchmark rounds: 7808969.964091 (ms)

================[ STATISTICS ]================
            *** Average result ***
ROUND
[+] Total test     : 1000000000
[+] Total correct  : 999999992
[+] Total runtime  : 328557.100229 (ms)
----------------------------------------------
ALGORITHM
[+] Average runtime: 0.000329 (ms)
[+] Average correct: 100.000000%
```

# Roadmap

-  [x] Miller Rabin algorithm
-  [x] Benchmark

# Contributors

<a href="https://github.com/QuanBlue/miller-rabin/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=QuanBlue/miller-rabin" />
</a>

Contributions are always welcome!

# Credits

-  [Cpp](https://www.cplusplus.com/)
-  [g++](https://gcc.gnu.org/)
-  [Miller-Rabin algorithm](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)
-  [Billion prime](https://github.com/bauripalash/bpp?fbclid=IwAR0z5uRxI1fYtzv9THQb5gK9iGbNGbEhZXM6av7V26RSVVOwcLU79AcAYlA_aem_AR9i2LabMtvQqOqQlC2kkDWeMgFsbRFR5XC9axt7Q_q6G3IbwCCDX9wqDMobiJ_M_UZFfk3cQsL3JQX2wo7btHh-)
-  [Generate prime](https://bigprimes.org/)
-  [Test is prime online](https://www.dcode.fr/primality-test)

# License

Distributed under MIT license. See
[LICENSE](./LICENSE) for more
information.

---

> Bento [@quanblue](https://bento.me/quanblue) &nbsp;&middot;&nbsp;
> GitHub [@QuanBlue](https://github.com/QuanBlue) &nbsp;&middot;&nbsp; Gmail quannguyenthanh558@gmail.com
