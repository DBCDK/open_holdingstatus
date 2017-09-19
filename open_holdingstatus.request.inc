<?php

/**
 * @file
 * OpenHoldingsStatus : open_holdingstatus class
 **/

class openHoldingsStatus extends TingClientRequest Implements ITingClientRequestCache {

  protected $agencyId;
  protected $pid;
  protected $lookupRecord;
  protected $responderId;
  protected $cacheKey;
  protected $outputType;
  protected $action;


  /* Implementation of ITingClientRequestCache */

  /** \brief ITingClientRequestCache::cacheKey; get a cachekey
   *
   * @return string
   **/
  public function cacheKey() {
    $params = $this->getParameters();
    $ret = '';
    $this->make_cache_key($params, $ret);

    return md5($ret);
  }

  /** \brief make a cachekey based on request parameters
   *
   * @param array $params
   * @param string $ret
   **/
  private function make_cache_key($params, &$ret) {
    foreach ($params as $key => $value) {
      if (is_array($value)) {
        // recursive
        $ret .= $key;
        $this->make_cache_key($value, $ret);
      }
      else {
        $ret .= $value;
      }
    }
  }

  /** \brief ITingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @return value of variable (drupal_get)
   **/
  public function cacheEnable($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_enable);
  }

  /** \brief set timeout of cache
   *
   * @return mixed value of variable (variable_get)
   **/
  public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  /** \brief implements ITingClientRequestCache::cacheBin
   *
   * @return string; name of cachebin
   **/
  public function cacheBin() {
    return 'cache_holdingstatus_webservice';
  }

  public function getAuthentication() {
    return $this->authentication;
  }

  public function setAuthentication($authentication) {
    $this->authentication = $authentication;
  }

  public function setAgencyId($value = NULL) {
    $this->agencyId = $value;
  }

  public function getAgencyId() {
    return $this->agencyId;
  }

  public function setMergePids($value = NULL) {
    $this->mergePid = $value;
  }

  public function getMergePids() {
    return $this->mergePid;
  }

  public function setPid($value = NULL) {
    $this->pid = $value;
  }

  public function getPid() {
    return $this->pid;
  }

  public function setLookupRecord($value = NULL) {
    $this->lookupRecord = $value;
  }

  public function getLookupRecord() {
    return $this->lookupRecord;
  }

  public function setResponderId($value = NULL) {
    $this->responderId = $value;
  }

  public function getresponderId() {
    return $this->responderId;
  }

  public function setAction($value = NULL) {
    $this->action = $value;
  }

  public function getAction() {
    return $this->action;
  }

  public function getCallback() {
    return $this->callback;
  }

  public function setCallback($callback) {
    $this->callback = $callback;
  }

  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  public function getOutputType() {
    return $this->outputType;
  }

  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }

}
