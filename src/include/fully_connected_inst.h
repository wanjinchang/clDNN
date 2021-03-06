/*
// Copyright (c) 2016 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "api/CPP/fully_connected.hpp"
#include "primitive_inst.h"

namespace cldnn
{
template <>
struct typed_program_node<fully_connected> : public typed_program_node_base<fully_connected>
{
public:
    auto& input() const { return get_dependency(0); }
    auto& weights() const { return get_dependency(1); }
    auto& bias() const { return get_dependency(2); }
};

using fully_connected_node = typed_program_node<fully_connected>;

template <>
class typed_primitive_inst<fully_connected> : public typed_primitive_inst_base<fully_connected>
{
    using parent = typed_primitive_inst_base<fully_connected>;

public:
    static layout calc_output_layout(fully_connected_node const& node);
    static std::string to_string(fully_connected_node const& node);

public:
    typed_primitive_inst(network_impl& network, fully_connected_node const& node);

    const memory& input_memory() const { return dep_memory(0); }
    const memory& weights_memory() const { return dep_memory(1); }
    const memory& bias_memory() const { return dep_memory(2); }
    bool bias_term() const { return !argument.bias.empty(); }
};

using fully_connected_inst = typed_primitive_inst<fully_connected>;

}
