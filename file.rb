f = File.new(ARGV[0])
File.open(f,"w") { |fi|
	fi.close
}

File.open(f,"a+") { |fi|
	fi.write(2)
	fi.close
}

