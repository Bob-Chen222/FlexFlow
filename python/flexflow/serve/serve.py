# Copyright 2023 CMU, Facebook, LANL, MIT, NVIDIA, and Stanford (alphabetical)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from flexflow.serve.models import FlexFlowLLAMA, FlexFlowOPT, FlexFlowFalcon
from flexflow.core import *
from transformers import AutoConfig
import sys

class SamplingConfig:
    def __init__(self, do_sample = False, temperature=0.9, topp=0.8, topk=1):
        self.do_sample = False
        self.temperature = 0.8
        self.topp = 0.6
        self.topk = 1

class LLM:
    def __init__(self, model_name, data_type="half"):
        self.model_name = model_name
        self.supported_models = {
            "LlamaForCausalLM": FlexFlowLLAMA,
            "LLaMAForCausalLM": FlexFlowLLAMA,
            "OPTForCausalLM": FlexFlowOPT,
            "RWForCausalLM": FlexFlowFalcon # falcon
        }
        self.model_type = self.__get_ff_model_type(model_name)
        self.data_type = data_type
        self.ffconfig = FFConfig()

    def __get_ff_model_type(self, model_name):
        hf_config = AutoConfig.from_pretrained(model_name)
        architectures = getattr(hf_config, "architectures", [])
        ff_arch = None
        if next(iter(architectures), None) is not None:
            ff_arch = self.supported_models.get(architectures[0])
        if ff_arch is None:
            print("Huggingface model of type {architectures} is not yet supported by FlexFlow")
            sys.exit(1)
        return ff_arch

    def compile(
        self,
        mode = InferenceMode.INC_DECODING_MODE,
        sampling_config = SamplingConfig(),
        use_full_precision = False,
        max_batch_size=1,
        max_seq_length=256,
        max_tokens_per_batch=64,
        tensor_parallel_degree=4,
        pipeline_parallel_degree=2,
        ssms=[],
    ):
        self.max_batch_size = max_batch_size
        self.max_seq_length = max_seq_length
        self.max_tokens_per_batch = max_tokens_per_batch
        self.tensor_parallel_degree = tensor_parallel_degree
        self.pipeline_parallel_degree = pipeline_parallel_degree
        self.ssms = ssms
        self.sampling_config = SamplingConfig()
        assert((mode == InferenceMode.INC_DECODING_MODE or mode == InferenceMode.BEAM_SEARCH_MODE) == (len(ssms) == 0))
        
        # Create model
        self.model = self.model_type(mode, sampling_config, self.ffconfig, max_batch_size, max_seq_length, max_tokens_per_batch, use_full_precision)

        # Create inference manager
        #self.im = InferenceManager(self.ffconfig, max_tokens_per_batch)

        # Create request manager
        #self.rm = RequestManager()
        
        assert False and "Not implemented yet"

    def generate(self, prompt, sampling=None):
        self.sampling = sampling if sampling is not None else self.default_config
        assert False and "Not implemented yet"