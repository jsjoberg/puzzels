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
    echo not ok: "expected $exp", got "$res"
    ok=1
  }
}

report() {
  [[ $ok == 0 ]] && echo PASS || echo FAIL
  exit $ok
}

# test suit
# test cases
tc 01a input1 3386686
tc 01b input1 5077155

report

