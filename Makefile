all:
	gcc tp1.c -o tp1

clean: 
	rm tp1
	
database: tp1-files-1 tp1-files-2
	unzip cities15000.zip

tp1-files-1:
	curl -o countryinfo.txt "http://download.geonames.org/export/dump/countryInfo.txt"
	

tp1-files-2:
	curl -o cities15000.zip "http://download.geonames.org/export/dump/cities15000.zip"
