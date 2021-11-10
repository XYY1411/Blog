'use strict';

module.exports.author = function(hexo) {
    hexo.extend.helper.register('page_author', function() {
        let author = this.page.author || this.config.author;
        return author;
    });
}