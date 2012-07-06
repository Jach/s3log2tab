# s3log2tab

Convert logs in [S3 Log Format](http://docs.amazonwebservices.com/AmazonS3/latest/dev/LogFormat.html) to tab delimited for use with unix text processing tools

## Usage

	s3log2tab <log >outfile
	s3log2tab <log | cut -f2,6 | sort | uniq