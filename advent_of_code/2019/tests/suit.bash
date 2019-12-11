#!/usr/bin/env bash 
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." >/dev/null && pwd )"
fail=$(mktemp)
tc() {
	local name=${1##*/}
	local test=${2##*/}
	local res=$(mktemp)
	$DIR/$name < $DIR/tests/$test > $res
	cmp -s $res $DIR/tests/$name/$test && echo $name $test ok || {
		echo $name $test not ok >&2
		diff $res $DIR/tests/$name/$test >&2
		echo 1 > $fail
	}
	rm $res
}
for p in $DIR/tests/???
do
	for t in $p/*
	do
		tc $p $t &
	done
done
wait < <(jobs -p)
echo
if [[ -s $fail ]]
then
	echo FAIL >&2
	rm $fail
	exit 1
fi
echo PASS
rm $fail

