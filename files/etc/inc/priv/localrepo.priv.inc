<?php
/*
 * localrepo.priv.inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
global $priv_list;
$priv_list['page-system-localrepo'] = array();
$priv_list['page-system-localrepo']['name'] = "WebCfg - System: LocalRepo package";
$priv_list['page-system-localrepo']['descr'] = "Allow access to LocalRepo package GUI";
$priv_list['page-system-localrepo']['match'] = array();
$priv_list['page-system-localrepo']['match'][] = "pkg.php?xml=localrepo.xml*";
$priv_list['page-system-localrepo']['match'][] = "pkg_edit.php?xml=localrepo.xml*";
?>
