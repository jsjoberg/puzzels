package main

import "fmt"

func main() {
	n := 600851475143
	d := 2
	w := 0
	for n > 2 {
		if n%d == 0 {
			w = n
			n /= d
		} else {
			d++
		}
	}
	fmt.Println(w)
}
