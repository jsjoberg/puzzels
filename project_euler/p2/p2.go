package main

import "fmt"

func main() {
	a, b := 1, 2
	acc := 0
	for a < 4_000_000 {
		a, b = b, a+b
		if a%2 == 0 {
			acc += a
		}
	}
	fmt.Println(acc)
}
