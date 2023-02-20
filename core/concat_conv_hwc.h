// Copyright 2009-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "concat_conv.h"

OIDN_NAMESPACE_BEGIN

  class ConcatConvHWC final : public ConcatConv
  {
  public:
    ConcatConvHWC(const Ref<Engine>& engine, const ConcatConvDesc& desc);

    bool isSupported() const override;

    size_t getScratchByteSize() const override;
    void setScratch(const std::shared_ptr<Tensor>& scratch) override;

    void finalize() override;
    void submit() override;

  private:
    void updateSrc() override;
    void updateWeight() override;
    void updateBias() override;
    void updateDst() override;

    Ref<Engine> engine;
    bool finalized = false;

    TensorDesc weight1Desc;
    TensorDesc weight2Desc;

    std::shared_ptr<Conv> conv1;
    std::shared_ptr<Conv> conv2;
  };

OIDN_NAMESPACE_END