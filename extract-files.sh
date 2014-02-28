#!/bin/sh

set -e

export DEVICE=shooter
export VENDOR=htc
../msm8660-common/extract-files.sh $@
