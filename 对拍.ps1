$y = 0
for ($x = 1000; $x -lt 2500; $x=$x+1)
{
    cat ".\hw11datas\fileIn$x.txt" | java -jar hw_11.jar > ".\hw11_out\stdout$x.txt" 
    for($z=2;$z -lt 7;$z=$z+1) {
        $name="$z.jar"
        cat ".\hw11datas\fileIn$x.txt" | java -jar $name > ".\hw11_out_$z\stdout$x.txt"
        #cat "$z"
        $dir = "hw11_out_$z"
        $err = "error_$z"
        if($(diff (cat ".\hw11_out\stdout$x.txt") (cat ".\$dir\stdout$x.txt"))) {
            echo "------------------------------------------------------------"
            echo "testpoint $x are failed, ZJY and $z are different!!!!!!!!!" 
            cat ".\hw11_out\stdout$x.txt" > ".\$err\stderr_zjy_$x.txt"
            cat ".\$dir\stdout$x.txt" > ".\$err\stderr_$z_$x.txt"
            cat  ".\hw11datas\fileIn$x.txt" >  ".\$err\stderrInput$x.txt"
            echo "------------------------------------------------------------"
            $y=$y+1
        }else {
            echo "testpoint $x are passed, $z and ZJY are Same"
            rm ".\$dir\stdout$x.txt"
        }
    }
    rm ".\hw11_out\stdout$x.txt"
}

if(!$y){
echo "NO_ERROR_THIS_TIME"
echo "Congratulation !ALL friends finish testpoints of $x"
}
