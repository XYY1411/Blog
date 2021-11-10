'use strict';

module.exports.description = function(hexo) {
    hexo.extend.helper.register('page_description', function() {
        let description = this.page.description || this.config.description;
        return description;
    });
}