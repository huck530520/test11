aaa# Description

This is a repository for testing Gerrit operation.
You can do anything here to test and try Gerrit server,
such as uploading change to Gerrit, cod review and veriry.

* [PSP SDLC Gerrit](http://psp.sdlc.rd.realtek.com/gerrit/)
* [PSP SDLC Jenkins](http://psp.sdlc.rd.realtek.com/jenkins/)

# Quick Start

## repo client
``
$ cd test
$ repo start my-topic .
<make any change>
$ git commit -a -m "my change"
$ repo upload .
``

## git-review
``
$ git checkout -b my-topic
<make any change>
$ git review
``

## git
``
$ git checkout -b my-topic
<make any change>
$ git push origin my-topic:refs/for/master
``

# Sanbox Branch

This repository supports -sandbox branch-.

This means, you can push branch directly to the branches
with following name:
* ``sandbox/<your_account>/<branch_name>``

For example:

* push
  ``$ git push origin master:sandbox/shunyen/my-test``

* force push
  ``$ git push -f origin HEAD:sandbox/shunyen/my-test``

* delete remote branch
  ``$ git push origin :sandbox/shunyen/my-test``

# Project Owner

If you would like to get project owner permission for testing.
Please let me know: <shunyen@realtek.com>

# Resource

To get more information, please visit our wiki page:
* [SDLC wiki](https://wiki.realtek.com/pages/viewpage.action?pageId=94440157)

