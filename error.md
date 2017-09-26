# Error
Building native extensions.  This could take a while...
ERROR:  Error installing rails:
	ERROR: Failed to build gem native extension.

    current directory: /home/elsyser/.rvm/gems/ruby-2.3.4/gems/nokogiri-1.8.1/ext/nokogiri
/home/elsyser/.rvm/rubies/ruby-2.3.4/bin/ruby -r ./siteconf20170926-3485-1t6gid4.rb extconf.rb
checking if the C compiler accepts ... *** extconf.rb failed ***
Could not create Makefile due to some reason, probably lack of necessary
libraries and/or headers.  Check the mkmf.log file for more details.  You may
need configuration options.

Provided configuration options:
	--with-opt-dir
	--without-opt-dir
	--with-opt-include
	--without-opt-include=${opt-dir}/include
	--with-opt-lib
	--without-opt-lib=${opt-dir}/lib
	--with-make-prog
	--without-make-prog
	--srcdir=.
	--curdir
	--ruby=/home/elsyser/.rvm/rubies/ruby-2.3.4/bin/$(RUBY_BASE_NAME)
	--help
	--clean
/home/elsyser/.rvm/rubies/ruby-2.3.4/lib/ruby/2.3.0/mkmf.rb:456:in `try_do': The compiler failed to generate an executable file. (RuntimeError)
You have to install development tools first.
	from /home/elsyser/.rvm/rubies/ruby-2.3.4/lib/ruby/2.3.0/mkmf.rb:571:in `block in try_compile'
	from /home/elsyser/.rvm/rubies/ruby-2.3.4/lib/ruby/2.3.0/mkmf.rb:522:in `with_werror'
	from /home/elsyser/.rvm/rubies/ruby-2.3.4/lib/ruby/2.3.0/mkmf.rb:571:in `try_compile'
	from extconf.rb:138:in `nokogiri_try_compile'
	from extconf.rb:162:in `block in add_cflags'
	from /home/elsyser/.rvm/rubies/ruby-2.3.4/lib/ruby/2.3.0/mkmf.rb:629:in `with_cflags'
	from extconf.rb:161:in `add_cflags'
	from extconf.rb:407:in `<main>'

To see why this extension failed to compile, please check the mkmf.log which can be found here:

  /home/elsyser/.rvm/gems/ruby-2.3.4/extensions/x86_64-linux/2.3.0/nokogiri-1.8.1/mkmf.log

extconf failed, exit code 1

Gem files will remain installed in /home/elsyser/.rvm/gems/ruby-2.3.4/gems/nokogiri-1.8.1 for inspection.
Results logged to /home/elsyser/.rvm/gems/ruby-2.3.4/extensions/x86_64-linux/2.3.0/nokogiri-1.8.1/gem_make.out
