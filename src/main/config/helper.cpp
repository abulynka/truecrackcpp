#include "helper.h"
#include "info.h"
#include "utils/strings.h"

namespace config {

const std::string& Helper::GetHeader() {
  if (usage_.empty()) {
    auto eol = utils::Strings::eol;

    usage_ = Info::SOFTWARE + " " + Info::VERSION + eol
        + "Author: " + Info::WEBSITE + eol
        + "Website: " + Info::WEBSITE + eol
        + "Contact: " + Info::EMAIL + eol
        + Info::MESSAGE + eol
        + "Usage for Dictionary attack:" + eol
        + "   " + Info::PROGRAM_NAME + " -t truecrypt_file -w passwords_file [-k ripemd160 | -k sha512 | -k whirlpool] [-e aes | -e serpent | -e twofish] [-a blocks] [-b] [-H] [-r number]" + eol
        + "Usage for Alphabet attack:" + eol
        + "   " + Info::PROGRAM_NAME + " -t truecrypt_file -c alphabet [-s minlength] -m maxlength [-p string] [-k ripemd160 | -k sha512 | -k whirlpool] [-e aes | -e serpent | -e twofish] [-a blocks] [-b] [-H] [-r number]" + eol
        + "Sample for Dictionary attack:" + eol
        + "   " + Info::PROGRAM_NAME + " -t volume.tc -w dictionary.txt" + eol
        + "Sample for Alphabet attack:" + eol
        + "   " + Info::PROGRAM_NAME + " -t volume.tc -c \"1234567890\" -s 4 -m 6";
  }

  return usage_;
}

} // config