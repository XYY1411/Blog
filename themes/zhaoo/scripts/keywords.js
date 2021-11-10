'use strict';

module.exports.keywords = function(hexo) {
    hexo.extend.helper.register('page_keywords', function() {
        let keywords = this.config.keywords;
        if (this.page.keywords) {
            if (keywords != null) {
                keywords += ", ";
            }
            keywords += this.page.keywords;
        }
        return keywords;
    });
}