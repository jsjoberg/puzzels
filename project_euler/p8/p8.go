package main

import (
	"fmt"
	"io/ioutil"
)

func main() {
	var a [13]byte
	b, _ := ioutil.ReadFile("input.txt")
	i := 0
	for c := 0; c < 12; i++ {
		if b[i] <= '9' && b[i] >= '0' {
			a[c] = b[i] - '0'
			c++
		}
	}
	w := 0
	for ; i < len(b); i++ {
		if b[i] <= '9' && b[i] >= '0' {
			a[12] = b[i] - '0'
			t := int(a[12])
			for i := 0; i < 12; i++ {
				t *= int(a[i])
				a[i] = a[i+1]
			}
			if t > w {
				w = t
			}
		}
	}
	fmt.Println(w)
}
