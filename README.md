# Evaluarea performantei procesoarelor x86-64
## Lucrare de diploma

CPU performance assessment tool written in C/C++ that utilises a workload which revolves around **finding large Fibonacci numbers**.\
Computing these numbers is being achieved using a **BigInt** class that allows for arithmetic operations in the case of very large numbers that wouldn't otherwise fit into any native C++ data type.

The application will be terminal-based and should run on Windows, Linux and macOS, without the use of any external libraries or dependencies.\

Current features:
* Stress Test
	* All-Core Stress Test
* Benchmark
	* Single-Core Benchmark
* SysInfo

Features to be added:
* Benchmark
	* Multi-Core Benchmark