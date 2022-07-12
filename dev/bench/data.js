window.BENCHMARK_DATA = {
  "lastUpdate": 1657656648372,
  "repoUrl": "https://github.com/williamhammond/engine",
  "entries": {
    "Windows Latest MSVC-Release": [
      {
        "commit": {
          "author": {
            "name": "williamhammond",
            "username": "williamhammond"
          },
          "committer": {
            "name": "williamhammond",
            "username": "williamhammond"
          },
          "id": "38a6f8e82a29fa552a38c0e96ef45905e02d4998",
          "message": "Adds benchmark action",
          "timestamp": "2022-06-22T18:26:59Z",
          "url": "https://github.com/williamhammond/engine/pull/10/commits/38a6f8e82a29fa552a38c0e96ef45905e02d4998"
        },
        "date": 1657656640960,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_StringCreation",
            "value": 0.38563309999995,
            "unit": "ns/iter",
            "extra": "iterations: 1000000000\ncpu: 0.390625 ns\nthreads: 1"
          },
          {
            "name": "BM_StringCopy",
            "value": 0.38548170000001386,
            "unit": "ns/iter",
            "extra": "iterations: 1000000000\ncpu: 0.390625 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}