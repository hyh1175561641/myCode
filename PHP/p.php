/*
*	代码已失效
*/
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>pic</title>
</head>
<body>
<form action="" method="GET">
<input type="text" name="start">-
<input type="text" name="end">
<input type="submit" value="submit" name="submit">
</form>
<?php
$start=$_GET['start'];
$end=$_GET['end'];
if($start<$end){$temp=$start;$start=$end;$end=$temp;}
if(!$start){$start=$end;}
if(!$end){$end=$start;}
if(isset($_GET['submit'])){
    for ($j=$start; $j>=$end; $j--){
	    for ($i=1; $i<=70; $i++){
	echo "<img src=\"http://img1.mm131.com/pic/".$j."/".$i.".jpg\" width=\"304\">"."<br>\n";
	    }
    }
}
?>
</body>
</html>
