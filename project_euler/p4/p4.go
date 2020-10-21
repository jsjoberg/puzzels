package main

import "fmt"

func main() {
	w := 0
	for i := 100; i < 1000; i++ {
		for j := i; j < 1000; j++ {
			n := i * j
			if n < w {
				continue
			}
			r := 0
			for t := n; t > 0; t /= 10 {
				r *= 10
				r += t % 10
			}
			if n == r {
				w = n
			}
		}
	}
	fmt.Println(w)
}
