//
//  main.cpp
//  dataloader
//
//  Created by User on 11/15/22.
//

#include "data_generator.h"
#include <ctime>
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

// This is for testing the request generator standalone
int main(int argc, char const *argv[]) {

  cout << "Starting the Data DataGenerator!\n";

  // DataGenerator parameters
  size_t total_requests = 2560;
  size_t vocab_size = 51200;
  size_t max_sequence_length = 256;
  bool use_poisson_distr = true;
  // average number of request arrivals per second
  double lambda = 250;

  size_t min_input_tokens = 8, max_input_tokens = 128,
         min_tokens_to_generate = 1,
         max_tokens_to_generate = max_sequence_length - max_input_tokens;

  int *requests =
      (int *)calloc(max_sequence_length * total_requests, sizeof(int));

  DataGenerator data_generator(total_requests,
                               vocab_size,
                               min_input_tokens,
                               max_input_tokens,
                               min_tokens_to_generate,
                               max_tokens_to_generate,
                               use_poisson_distr,
                               lambda);
  data_generator.generate_requests(requests);
  bool simulation = false;
  if (simulation) {
    data_generator.start_timer();

    size_t received_requests = 0;
    std::pair<size_t, size_t> reqs = data_generator.get_requests(0, 0);
    size_t guid = reqs.first;
    assert(reqs.second == 0);
    this_thread::sleep_for(milliseconds(50));

    reqs = data_generator.get_requests(2560, 2560 * (512));
    received_requests += reqs.second;
    std::cout << "t=0ms: received " << received_requests << std::endl;

    this_thread::sleep_for(milliseconds(1200));
    reqs = data_generator.get_requests(2560, 2560 * (512));
    received_requests += reqs.second;
    std::cout << "t=1200ms: received " << received_requests << std::endl;

    this_thread::sleep_for(milliseconds(10));
    reqs = data_generator.get_requests(2560, 2560 * (512));
    received_requests += reqs.second;
    std::cout << "t=1210ms: received " << received_requests << std::endl;

    this_thread::sleep_for(milliseconds(4000));
    reqs = data_generator.get_requests(2560, 2560 * (512));
    received_requests += reqs.second;
    std::cout << "t=5210ms: received " << received_requests << std::endl;
    this_thread::sleep_for(milliseconds(5000));

    reqs = data_generator.get_requests(2560, 2560 * (512));
    received_requests += reqs.second;
    std::cout << "t=10210ms: received " << received_requests << std::endl;

    assert(received_requests == total_requests);
  } else {
    // just print the requests
    std::string fpath("./arrival_times.txt");
    assert(data_generator.print_arrival_times(fpath));
    std::string fpath1("./request_tokens.txt");
    std::string fpath2("./tokens_to_generate.txt");
    assert(data_generator.print_all_requests(
        requests, max_sequence_length, fpath1, fpath2));
  }
  free(requests);

  return 0;
}