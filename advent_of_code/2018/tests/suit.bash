#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." >/dev/null && pwd )"

ok=0

tc () {
  local name="$1"
  local input="$2"
  local exp="$3"

  echo -n "$name: "
  make -s $DIR/$name || {
    ok=1
    return
  }

  local res="$($DIR/$name < $DIR/tests/$input)"

  [[ "$exp" == "$res" ]] && echo ok || {
    echo not ok: "expected $exp", observed "$res"
    ok=1
  }
}

report() {
  [[ $ok == 0 ]] && echo PASS || echo FAIL
  exit $ok
}

# test suit
# test cases
tc 01a input1 400
tc 01b input1 232
tc 02a input2 7134
tc 02b input2 kbqwtcvzhmhpoelrnaxydifyb
tc 03a input3 113966
tc 03b input3 235
tc 04a input4 94040
tc 04b input4 39940
tc 05a input5 10762
tc 05b input5 6946

report

