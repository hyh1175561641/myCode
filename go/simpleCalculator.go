package main
import "fmt"

func main(){

  var a int
  var b int
	var c string
	var d int
for {
  fmt.Scanf("%d",&a)
	fmt.Scanf("%s",&c)
	fmt.Scanf("%d",&b)

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
		fmt.Println("Errow")
	}

//	fmt.Println(a,b,c)
	fmt.Println(d)
}

}
