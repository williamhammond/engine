#include <benchmark/benchmark.h>
#include <float.h>

#include "math/fmath.h"

static void benchmark_square(benchmark::State& state) {
  for (auto _ : state) {
    engine::FMath::square(2.0f);
  }
}
BENCHMARK(benchmark_square);

static void benchmark_sqrt_100(benchmark::State& state) {
  for (auto _ : state) {
    engine::FMath::sqrt(100.0f);
  }
}
BENCHMARK(benchmark_sqrt_100);

static void benchmark_sqrt_max(benchmark::State& state) {
  for (auto _ : state) {
    engine::FMath::sqrt(FLT_MAX);
  }
}
BENCHMARK(benchmark_sqrt_max);

static void benchmark_pow(benchmark::State& state) {
  for (auto _ : state) {
    engine::FMath::pow(2.5f, 10);
  }
}
BENCHMARK(benchmark_pow);

static void benchmark_pow_max(benchmark::State& state) {
  for (auto _ : state) {
    engine::FMath::pow(2.5f, INT32_MAX);
  }
}
BENCHMARK(benchmark_pow_max);

BENCHMARK_MAIN();