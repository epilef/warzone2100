<?PHP
if ($argc == 2)
{
	$lines = file($argv[1]);
	$c_lines = count($lines);
	$array01 = explode(",", $lines[0]);
	$array01 = array_map('trim',  $array01 );
	// chech if this is a multi value csv
	$arr1 = explode(",", $lines[1]);
	$arr2 = explode(",", $lines[2]);
	$multivalue = false;
	if ($arr1[0] == $arr1[1]) {$multivalue = true;}
	if (!$multivalue) 
	{
		for($i=1;$i<$c_lines;$i++) {
			$arrayd = explode(",", $lines[$i]);
			$c_arrayd = count($arrayd);
			$data.="[".$arrayd[0]."]\n";
			for ($x=1;$x<$c_arrayd;$x++) {
				$field = $arrayd[$x];
				if (strpos( $field, ' '))
					{ $field = "\"".$field."\""; }
				$data.=$array01[$x]." = ".$field."\n";
			}
		}
	} else {
		$lastsection = "";
		// $section[] = "";
		$fpas = true;
		for($i=1;$i<$c_lines;$i++) {
			$arrayd = explode(",", $lines[$i]);
			$c_arrayd = count($arrayd);
			if ( $lastsection != $arrayd[0] ) {
				if ($section) foreach ($section as $iniline) $data .= $iniline."\n";
				$data.="[".$arrayd[0]."]\n";
				$lastsection = $arrayd[0];
				unset($section);
				$fpas = true;
			}
			for ($x=1;$x<$c_arrayd;$x++) {
				$field = $arrayd[$x];
                                if (strpos( $field, ' '))
                                        { $field = "\"".$field."\""; }
				$field = trim($field, "\n");
				if ($fpas)  
					$section[$x] = $array01[$x]." = ".$field;
				else
					$section[$x] .= ",".$field;
					
			}
			$fpas = false;
		}	
		foreach ($section as $iniline) $data .= $iniline."\n";
	}
 	echo $data;
}
else
{
	echo "\n";
	echo "Usage: php csv2ini.php file.csv > file.ini\n";
	echo "\n";
}
?>
