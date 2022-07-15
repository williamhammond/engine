#include <benchmark/benchmark.h>
#include <float.h>

#include "math/utils.h"

static void benchmark_square(benchmark::State& state) {
  for (auto _ : state) {
    Utils::square(2.0f);
  }
}
BENCHMARK(benchmark_square);

static void benchmark_sqrt_100(benchmark::State& state) {
  for (auto _ : state) {
    Utils::sqrt(100.0f);
  }
}
BENCHMARK(benchmark_sqrt_100);

static void benchmark_sqrt_max(benchmark::State& state) {
  for (auto _ : state) {
    Utils::sqrt(FLT_MAX);
  }
}
BENCHMARK(benchmark_sqrt_max);

static void benchmark_pow(benchmark::State& state) {
  for (auto _ : state) {
    Utils::pow(2.5f, 10);
  }
}
BENCHMARK(benchmark_pow);

static void benchmark_pow_max(benchmark::State& state) {
  for (auto _ : state) {
    Utils::pow(2.5f, INT32_MAX);
  }
}
BENCHMARK(benchmark_pow_max);

BENCHMARK_MAIN();