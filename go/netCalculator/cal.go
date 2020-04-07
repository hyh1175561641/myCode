package main
import "fmt"

func calcul(shout string){

  	var a int
  	var b int
	var c string
	var d int


	
//	Len := 20
//	s:= [Len]byte
	for i := 0; shout[i] != 0; i++ {
		nextChar := shout[i]
		fmt.Println(nextChar)
	}

	switch c {
	case "+" :
		d=a+b
	case "-":
		d=a-b
	case "*":
		d=a*b
	case "/":
		d=a/b
	default:
		d=0
	
	fmt.Println(d)
}

}

func main(){

	calcul("3+2")


}